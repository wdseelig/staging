<?php
$mystr = "47,48,40+23,24,25,78,56";
$firstsplit = array();
$firstsplit = explode("+",$mystr);
$secondsplit = explode(",",$firstsplit[1]);
print_r ($firstsplit);
printf("<br><br>Here is somethng in between splits<br><br>");
print_r($secondsplit);
printf("<br><br>Here is somethng in between splits<br><br>");
foreach ($secondsplit as $key => $value){
	printf("<br>The arraykey is " . $key . " and the value is: " . $value);
}
?>