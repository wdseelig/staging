<?php
printf("\n\nhello world on this fine May 10th morning!");
phpinfo();
$inipath = php_ini_loaded_file();
if ($inipath) {
    echo 'Loaded php.ini: ' . $inipath;
} else {
    echo 'A php.ini file is not loaded';
}
$tstmp = 1441044069;
print ("<br><br>The timestamp is:  " . $tstmp);
print ("<br><br>And the date of that timestamp is:  " . date(' M/d/Y h:i A', $tstmp));

?>
