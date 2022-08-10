#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WiFiMulti.h>
#include<ESP8266WebServer.h>
#include<FS.h>
#include<SoftwareSerial.h>

const int BUFFER_SIZE = 500;
char buf[BUFFER_SIZE];
int i;

SoftwareSerial espSerial(3,1);

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

File fsUploadFile;
//bool handleFileRead(String Path);
void handleFileUpload();
bool fileUploaded = false;

void setup() {
  // put your setup code here, to run once:
  espSerial.begin(9600);
  delay(10);
  //espSerial.println("\n");
  
  //Credentials
  wifiMulti.addAP("Cncphone", "Invoker2000");
  
  //Connection
  //espSerial.println("Connecting to...");
  while(wifiMulti.run() != WL_CONNECTED) {
    delay(1000);
    //espSerial.print(".");
  }
  //Display Connection Details
  //espSerial.println('\n');
  //espSerial.print("Connected to ");
  //espSerial.println(WiFi.SSID());
  //espSerial.print("IP address:\t");
  //espSerial.println(WiFi.localIP());

  //Begin File System
  SPIFFS.begin();

  //Handle upload request
  server.on("/upload", HTTP_GET, []() {
    if(!handleFileRead("/upload.html"))
      server.send(404, "text/plain", "404: Not Found");
  });
  server.on("/upload", HTTP_POST, [](){
    server.send(200);},
    handleFileUpload
   );
  server.onNotFound([]() {                              // If the client requests any URI
   if (!handleFileRead(server.uri()))                  // send it if it exists
     server.send(404, "text/plain", "404: Not Found"); // otherwise, respond with a 404 (Not Found) error
  });

  server.begin();
  //espSerial.println("HTTP SERVER STARTED!"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

bool handleFileRead(String path){
  //espSerial.println("HandleFileRead : " + path);
  if(SPIFFS.exists(path)){
    File file = SPIFFS.open(path, "r");
    size_t sent = server.streamFile(file, "text/html");
    file.close();
    //espSerial.println(String("\tSent File: ") + path);
    return true;
  }
  //espSerial.println("File Does Not Exist");
  return false;
}

void handleFileUpload(){
  HTTPUpload& upload = server.upload();
  if(upload.status == UPLOAD_FILE_START){
    String filename = upload.filename;
    if(!filename.startsWith("/")) filename = "/"+filename;
    //espSerial.print("handleFileUpload Name: ");//espSerial.println(filename);
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  }else if(upload.status == UPLOAD_FILE_WRITE){
    if(fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize);
  }else if(upload.status == UPLOAD_FILE_END){
    if(fsUploadFile){
      fsUploadFile.close();
      //espSerial.print("handleFileUpload Size : ");//espSerial.println(upload.totalSize);
      server.sendHeader("Location","/success.html");
      server.send(303);
      if(fileUploaded==false){
        fileUploaded=true;
        File file = SPIFFS.open("/gcodefile.gcode", "r");
        if(!file){
          espSerial.println("FILE NOT FOUND!");
          return;
        }
        while(file.available()){
          sendGcodes(file);
        }
        file.close();
      }
    }else{
      server.send(500, "text/plain", "500: Couldn't find the file");
    }
  }
}

void displayContents(){
  fileUploaded = false;
  File file = SPIFFS.open("/gcodefile.gcode", "r");
  if(!file){
    //espSerial.println("FILE NOT FOUND!");
    return;      
  }
  //espSerial.println("\nFILE CONTENT: ");
  while(file.available()){
    //espSerial.write(file.read());
  }
  file.close();
}

void sendGcodes(File file){
  String res, str;
   memset(buf, 0, sizeof(buf));
  //espSerial.println("\nFILE CONTENT: ");
    int len = file.readBytesUntil('\n', buf, BUFFER_SIZE);
    while(len==1){
      len = file.readBytesUntil('\n', buf, BUFFER_SIZE);
    }
    i=0;
    while(i<len){
      espSerial.write(buf[i]);
      i++;
    }
    espSerial.flush();
    //delay(500);
    while(!espSerial.available());
    while(true){
      res = espSerial.readStringUntil('\n');
      if(res.startsWith("ok")||res.startsWith("error")){
        return;
      }
    }
}
