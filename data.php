<?php
$test = false;
$mile = isset($_GET["m"]);
if ($test)
{
echo "<s>".rand (0,120)."</s><l>".rand (0,120)."</l><e>1</e>";
}
else 
{
$jsonIterator = new RecursiveIteratorIterator(
    new RecursiveArrayIterator(json_decode(file_get_contents("http://localhost:25555/api/ets2/telemetry"), TRUE)),
    RecursiveIteratorIterator::SELF_FIRST);
foreach ($jsonIterator as $key => $val) {
    if(!is_array($val)) {
        if ($mile)
        {
        if ($key == "speed")
        echo "<s>".round($val*0.621371)."</s>";

        if ($key == "speedLimit")
        echo "<l>".round($val*0.621371)."</l>";

        if ($key == "engineOn")
        echo "<e>".$val."</e>";
        }
        else {
        if ($key == "speed")
        echo "<s>".round($val)."</s>";

        if ($key == "speedLimit")
        echo "<l>".round($val)."</l>";

        if ($key == "engineOn")
        echo "<e>".$val."</e>";
        }
    }
}
}
?>
