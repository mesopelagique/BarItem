//%attributes = {}

var $mouseX; $mouseY : Real
var $mouseButton : Integer
GET MOUSE:C468($mouseX; $mouseY; $mouseButton)

Case of 
	: ($mouseButton=2)  // right click
		var $refMainContextMenu; $refMenuEdit : Text
		$refMainContextMenu:=Create menu:C408
		APPEND MENU ITEM:C411($refMainContextMenu; "menu item 1")
		SET MENU ITEM PARAMETER:C1004($refMainContextMenu; -1; "1")
		APPEND MENU ITEM:C411($refMainContextMenu; "menu item 2")
		SET MENU ITEM PARAMETER:C1004($refMainContextMenu; -1; "2")
		
		var $paramRef : Text
		$paramRef:=Dynamic pop up menu:C1006($refMainContextMenu; ""; $mouseX-22; 22)
		RELEASE MENU:C978($refMainContextMenu)
		
		Case of 
			: ($paramRef="1")
				ALERT:C41("1")
			: ($paramRef="2")
				ALERT:C41("2")
		End case 
		
	: ($mouseButton=0)
		
	: ($mouseButton=1)
		ALERT:C41("left click")
		
End case 





