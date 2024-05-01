const express = require("express");
const http = require("http");
const multiparty = require("connect-multiparty");
const fs = require("fs");
const path = require("path");
const port = 80;//http

let received_path = path.join(__dirname, "received_files");//saves all files to a seperate folder
if(!fs.existsSync(received_path)){//create folder if not exists
    console.log(`${received_path} does not exist, will attempt to create a directory.`);
    fs.mkdir(received_path, (err) => {
    if (err) {
        throw err;
    }
    console.log(`Made a directory at: ${received_path}`);
});
}
const multipartyMiddleware = multiparty({ uploadDir: received_path});


let app = express();

const http_server = http.createServer(app).listen(port, function (req, res) {
	console.log("Running on port " + port);
});

app.post("/", multipartyMiddleware, function (req, res) {
	let ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress || req.socket.remoteAddress || (req.connection.socket ? req.connection.socket.remoteAddress : null);
	let current_time = return_time();
	console.log(current_time + " : Connection from " + ip);
	console.log(req.files);
	let file = req.files.file;
	file_log(path.join(received_path, "connection_log.txt"), ip, current_time, file.path, file.name);
	res.end();
});

app.get("/:filename", function (req, res) {//could be used for downloads
    try{
        res.sendFile(path.join(__dirname, "/scripts" , req.params.filename));
    }catch(e){
        res.redirect("/");
    }
});

function file_log(log_file, ip, time, file_received, received_name) {//logs original file name, ip and time received
	fs.appendFile(log_file, `${time} : Connection from ${ip}: ${file_received} (${received_name}))\n`, () => {
		console.log(`Saved to ${log_file}`);
	});
}

function return_time() {
	let date_ob = new Date();
	let date = ("0" + date_ob.getDate()).slice(-2);
	let month = ("0" + (date_ob.getMonth() + 1)).slice(-2);
	let year = date_ob.getFullYear();
	let hours = date_ob.getHours();
	let minutes = date_ob.getMinutes();
	let seconds = date_ob.getSeconds();
	let dateDisplay = `${date}/${month}/${year} ${hours}:${minutes}:${seconds}`;
	return dateDisplay;
}
