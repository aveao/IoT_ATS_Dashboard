<?php
$jsonIterator = new RecursiveIteratorIterator(
    new RecursiveArrayIterator(json_decode(file_get_contents("http://localhost:25555/api/ets2/telemetry"), TRUE)),
    RecursiveIteratorIterator::SELF_FIRST);

foreach ($jsonIterator as $key => $val) {
    if(!is_array($val)) {
        if ($key == $_GET["key"])
        echo "<val>".$val."</val>";
    }
}
?>
