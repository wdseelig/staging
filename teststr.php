<?php
printf("<br><br><h2>Hello there, we are experimenting with strings!");
$teststring = "http://www.wash-gop.com/sites/all/files/trialimporter_append.c";
$splitstr = explode(".csv", $teststring);
printf("br><br><h2>The first value is: " . $splitstr[0] . " and the second is "
	. $splitstr[1]);
$endstring = substr($splitstr[0],-7);
printf("<br><br><h2>The last seven characters are: " . $endstring);
$allatonce = substr(explode(".csv",$teststring)[0],-7);
printf("<br><br>The allatonce value is: " . $allatonce);
$justlast11 = substr($teststring,-11);
printf("<br><br><h2>The just last 11 are: " . $justlast11);
if (substr($teststring, -11) === "_append.csv")
		printf("<br><br>Yup, we have a match");
	else
		printf("br><br>Nope, Nothing to see here!");
	
?>