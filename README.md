# e-Desk
IOT School project

## Introduction
![Idesk - 3D Plan](https://github.com/FlorianBergeron/idesk/blob/master/img/3D_plan.png)

The current health crisis has increased the acceptance and popularization of telecommuting. As a result, employees are increasingly looking to properly equip themselves at home to work and companies are unlocking bonuses for these expenses, so there is a niche being created.
So we thought of the following solution:
* Desktop capable of adapting its brightness according to the ambient light. 
* Able to cool the user when it is too hot, and color that changes according to this same temperature (cold color when it is hot and vice versa). 
* LCD screen capable of displaying the temperature.
* A fan that turns on / off according to the ambient temperature of the room and is able to modulate itself according to it.
* Buttons to activate / deactivate LEDs, fan and the entire system.

## How it works
The user has several ways to use his desktop, once it is initialized. He can simply let the sensors manage the different functionalities mentioned above or use his mobile application to adjust the color of the LEDs or modulate the intensity of his fan (see technical diagram - big data infrastructure):

![big data infrastructure](https://github.com/FlorianBergeron/idesk/blob/master/img/Big_data_infrastructure.png)

## Hardware
**Arduino - UNO**

![Arduino - UNO](https://www.d4online.com/Web/WebShopImages/landscape_large/9-/01/arduino-a000066.jpg)

**Temperature sensor**

![Temperature Sensor](https://cdn11.bigcommerce.com/s-2fbyfnm8ev/images/stencil/1280x1280/products/345/1486/ED01-09-0049-A-600x6001__23921.1539996142.jpg?c=2)

**Light sensor**

![Light Sensor](https://user-images.githubusercontent.com/32666459/122382252-073f3d00-cf6a-11eb-807e-6640678b7b9d.png)

**NeoPixel (RGB) - Strip LED**

![NeoPixel (RGB) - Strip LED](https://cdn-shop.adafruit.com/1200x900/1507-00.jpg)

**DC Motor**

![DC Motor](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSm3pTTPrnztIT9NzikX_Pk-5bRmzjVN7ousA&usqp=CAU)

**LCD Screen**

![LCD Screen](https://raw.githubusercontent.com/OnionIoT/Onion-Docs/master/Omega2/Kit-Guides/img/lcd-screen.jpg)

**Power supply**

![Power Supply](https://www.elektor.com/media/catalog/product/cache/1404d1bfd8e1ad71cc6f16950ff5c805/1/7/17543_eu-91b-web.jpg)

**Breadboard**

![Breadboard](https://cdn.sparkfun.com//assets/parts/8/5/0/3/12002-Breadboard_-_Self-Adhesive__White_-03.jpg)

**Wifi-Board**

![Wifi-Board](https://static.generation-robots.com/4533-product_cover/module-serie-wifi-esp8266.jpg)

**Resistors**

![Resistors](https://images-na.ssl-images-amazon.com/images/I/31j9N%2BLKvIL._SX342_.jpg)

**Jumper wires**

![Jumper Wires](https://upload.wikimedia.org/wikipedia/commons/5/5c/A_few_Jumper_Wires.jpg)

## Circuit & cables managment

![Idesk - Circuit](https://github.com/FlorianBergeron/idesk/blob/master/img/Circuit.png)

[TinkerCad - Simulation](https://www.tinkercad.com/things/dVSjHSEyxxZ-copy-of-recevoir-nombre-du-moniteur-serie/editel?sharecode=8AuDeiMorbC4D-xe5-kdRXxgWL59hRrwepK516i-S3I)
