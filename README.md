# CloudMQTT

We are using CloudMQTT for broker, i.e you create instance in CloudMQTT where they have online
running broker where the data can be published and subscribed.
Here by using cloudMQTT we are controlling the RGB led to change its color by sending Analog Values from publish.py
in form "255,200,100"(consider as an example) and accordingly we are creating different color combination.

## Setting up CloudMQTT

- Go to site [CloudMQTT](https://customer.cloudmqtt.com/login) and register yourself.
- Create a new instance choose any one plan (free category or paid category).
- To create a topico r user either you can go to USERs -> Create by giving name and password(optional).
    or you can type command in cli :- 
curl -XPOST -d '{"username":"test", "password":"super_secret_password"}' -H "Content-Type:application/json" -u "       $CLOUDMQTT_USER:$CLOUDMQTT_PASSWORD" https://api.cloudmqtt.com/user.
- After all these click on Details where you will find all the credentials of that are required for authentication.
- For more details you can refer to [Setting up cloudMQTT](https://www.cloudmqtt.com/docs.html).

## Setting up NodeMcu(ESP8266)

- Here we are using two libraries of NodeMcu i.e ESP8266WiFi and PubSubClient.
- You can add these libraries by going to Sketch -> Include library -> Manage Libraries.
- Search for the above libraries and download them.
- Edit all the credentials of CloudMQTT in the code so that you are connected to broker running on that server.
- Connect D0,D1,D2 pins of NodeMCU to the respectivelegs of Led and start controlling the lights.

## Controlling of Light

- Run publish.py and Cli will ask for the input.
- Enter the message in a manner "255,50,100" to control the led. This is done to give different analog values to Led.
- By varying the leds in similar manner of messages you can create different color combinations.

### References

- https://techtutorialsx.com/2017/04/09/esp8266-connecting-to-mqtt-broker/
- https://techtutorialsx.com/2017/04/23/python-subscribing-to-mqtt-topic/
