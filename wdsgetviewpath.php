<?php
printf("/nEntering the get path routine");
$view_name = "Shopping cart summary";
$view = views_get_view($view_name, TRUE);
$path = $view->display['page']->display_options['path'];
printf ("/nThe view path is:  " . $path);
?>