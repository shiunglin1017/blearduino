#include <LWiFi.h>
#include <LWatchDog.h>
char ssid[] = "MES"; //WiFi名稱
char pass[] = "thuieei104"; //WiFi密碼
int status = WL_IDLE_STATUS; //狀態
char server[] = "140.128.118.18"; //NAS網址
WiFiClient client;
void setup() {
  Serial.begin(9600);
  Serial.println("System (re)Booted.");
  while (!Serial) {
        ; 
  }
  while (status != WL_CONNECTED) {  
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  Serial.println("Connected to wifi");
  
}

void loop() {
  int a=0;
  String b;
  for(int i=0 ;i<10 ; i++){
    a=a+1;
    b=String(a);
    Serial.println(a);
    if (client.connect(server,8888)) {
    Serial.println("connected to server (Server GET Data)");
    client.println("GET http://140.128.118.18:8888/20210706.php?+snesor="+b+"&pw=8888\r\n");
    client.println("Connection: close");
    client.println();
    delay(1000);
    }    
  }
}
void printWifiStatus(){
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
