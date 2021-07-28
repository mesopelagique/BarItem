# StatusBarItem

[![language][code-shield]][code-url]
[![language-top][code-top]][code-url]
![code-size][code-size]
[![license][license-shield]][license-url]
[![discord][discord-shield]][discord-url]
[![sponsors][sponsors-shield]][sponsors-url]
[![build](https://github.com/mesopelagique/StatusBarItem/actions/workflows/build.yml/badge.svg)](https://github.com/mesopelagique/StatusBarItem/actions/workflows/build.yml)
[![release](https://github.com/mesopelagique/StatusBarItem/actions/workflows/release.yml/badge.svg)](https://github.com/mesopelagique/StatusBarItem/actions/workflows/release.yml)
[![release](https://img.shields.io/github/v/release/mesopelagique/StatusBarItem.svg)](https://github.com/mesopelagique/StatusBarItem/releases/latest)

This 4d plugin allow to add status bar item to macOS simply by passing method to execute on click event and the picture icon.

```4d
STATUS BAR ITEM(<method name>; <icon>)
```

Example 

```4d
var $picture; $statusPicture : Picture
READ PICTURE FILE(Folder:C1567(fk resources folder).file("icon.png").platformPath; $picture)

CREATE THUMBNAIL($picture; $statusPicture; 20; 20)

STATUS BAR ITEM("ShowMenuOrAlert"; $statusPicture)
```

then in your method you could for instance open a form or display a menu (on right or left click) using mouse event information.

```4d
var $mouseX; $mouseY : Real
var $mouseButton : Integer
GET MOUSE($mouseX; $mouseY; $mouseButton)

Case of 
	: ($mouseButton=2)  // right click

		var $refMainContextMenu; $refMenuEdit : Text
		$refMainContextMenu:=Create menu
		APPEND MENU ITEM($refMainContextMenu; "menu item 1")
		SET MENU ITEM PARAMETER($refMainContextMenu; -1; "1")
		APPEND MENU ITEM($refMainContextMenu; "menu item 2")
		SET MENU ITEM PARAMETER($refMainContextMenu; -1; "2")
		
		var $paramRef : Text
		$paramRef:=Dynamic pop up menu($refMainContextMenu; ""; $mouseX-22; 22)
		RELEASE MENU($refMainContextMenu)
		
		Case of 
			: ($paramRef="1")
				ALERT("1")
			: ($paramRef="2")
				ALERT("2")
		End case 

	: ($mouseButton=1)
		ALERT("left click")
		
End case 
```

## To help

If you run a business and you’re using one of my projects in a revenue-generating product, it makes business sense to sponsor this open source development

[![sponsors][sponsors-shield]][sponsors-url]

Thank you for your support!

## Other components

[<img src="https://mesopelagique.github.io/quatred.png" alt="mesopelagique"/>](https://mesopelagique.github.io/)
 

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[code-shield]: https://img.shields.io/static/v1?label=language&message=4d&color=blue
[code-top]: https://img.shields.io/github/languages/top/mesopelagique/StatusBarItem.svg
[code-size]: https://img.shields.io/github/languages/code-size/mesopelagique/StatusBarItem.svg
[code-url]: https://developer.4d.com/
[license-shield]: https://img.shields.io/github/license/mesopelagique/StatusBarItem
[license-url]: LICENSE.md
[discord-shield]: https://img.shields.io/badge/chat-discord-7289DA?logo=discord&style=flat
[discord-url]: https://discord.gg/dVTqZHr
[sponsors-shield]: https://img.shields.io/github/sponsors/phimage?color=violet&logo=github
[sponsors-url]: https://github.com/sponsors/phimage
