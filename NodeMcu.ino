#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "";        //SSID
const char* password =  "";    //passward
const char* mqttServer = "";  //server address
const int mqttPort = portNumber;                    //server port
const char* mqttUser = "";             //User
const char* mqttPassword = "";     //password
const int RED = 5;                //Defining GPIO pin for D2
const int GREEN = 4;              //Defining GPIO pin for D1
const int BLUE = 16;             //Defining GPIO pin for D0

WiFiClient espClient;              //making object of wifiClient
PubSubClient client(espClient);    //making object of PubSubClient
 
void setup() {
 
  Serial.begin(115200);      

  pinMode(RED, OUTPUT);        
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
 
  WiFi.begin(ssid, password);

 //To make sure connection is established between accessPoint and NodeMcu
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

 //Setting server for MQTT 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.subscribe("parikshit/verigation");     //subscribe to topic
 
}

//Callback function used message arrival and further logic
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  char string[length];      
  char var[3][3];
  int num[3]= {0,0,0};
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)(payload[i]));
    string[i]=((char)(payload[i]));       //converting the byte into char and then storing into a string
  }
  Serial.println("");
  int m=0;
  int j=0;
  //To seperate the msg from comma and then storing in 2D character array
  for (int i=0 ; i< length && m<4;i++){
    if(string[i]!=','){
      var[j][m]=string[i];
      const char *b = &var[j][m];
      num[j] = (10*num[j])+ (atoi(b));
      m++;  
    }
    else{
      j+=1;
      m=0;
    }
  }
  //Calling function setColor to control the RGB led
  setColor(num)
  Serial.println();
  Serial.println("-----------------------");
 
}

void setColor(int payload[]){
  analogWrite(RED, payload[0]);  
  analogWrite(GREEN, payload[1]);
  analogWrite(BLUE, payload[2]);  
}
 
void loop() {
  client.loop();
}
