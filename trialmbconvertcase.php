<?php
printf("<h2>Let us see if this works</h2><br><br>");
$field = "THIS IS SOME STUFF IN ALL CAPS";
// $field = mb_strtoupper(mb_substr($field, 0, 1, 'UTF-8'), 'UTF-8') . mb_strtolower(mb_substr($field, 1, mb_strlen($field, 'UTF-8'), 'UTF-8'));
$field = mb_convert_case($field,MB_CASE_TITLE,'UTF-8');
printf("Post Conversion field: " . $field);
?>