# OLED_SSD1331 Icons and text displayed


* Use mage2cpp to to convert the Pictues to be displyed http://javl.github.io/image2cpp/)
	image2cpp is a simple tool to change images into byte arrays (or your array back into an image) for use with Arduino and displays such 		as OLEDs.
	This tool also works offline. Simply save the page to your computer and open the file in your browser.
	
	Set the Width and Hight in the funtion he sama as the picture to diesplyed
	void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t W, int16_t H, uint16_t color);

	E.g. 	icons8-apple-logo-60, (30)x(30)px
				display.drawBitmap(10, 30, AppleBitmap, 30, 30, WHITE);  
