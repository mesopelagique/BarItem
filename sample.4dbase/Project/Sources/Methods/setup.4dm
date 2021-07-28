//%attributes = {}

var $picture; $statusPicture : Picture
READ PICTURE FILE:C678(Folder:C1567(fk resources folder:K87:11).file("icon.png").platformPath; $picture)

CREATE THUMBNAIL:C679($picture; $statusPicture; 20; 20)

STATUS BAR ITEM("test"; $statusPicture)
