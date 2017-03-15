<!DOCTYPE html>
<html>
<body>

<?php

//DSA
//info: http://icsc.un.org/resources/sad/dsa/restr/sad-dsa-automate.asp
//$DSA_URL=http://icsc.un.org/getdoc_a.asp?user=UN.HM1&psw=IAUS1709&cat=ci&file=Circular072014.XML
$YOUR_ID = "UN.HM1";
$YOUR_PASSWORD = "IAUS1709";
$MM = date("m"); //Month when this converter is run
$YYYY = date("Y");
$EXT = "XML";
$DSA_URL = "http://icsc.un.org/getdoc_a.asp?user=".$YOUR_ID."&psw=".$YOUR_PASSWORD."&cat=ci&file=Circular".$MM.$YYYY.".".$EXT;
xmlToJson($DSA_URL, "data/dsa.json");

//Post Adjustment
xmlToJson("http://icsc.un.org/resources/cold/par/class/pac_xml.xml", "data/pa.json");

//Salary Scale
xmlToJson("http://icsc.un.org/resources/sad/ss/January2014.xml", "data/sp.json");

//Hardship Classification
xmlToJson("http://icsc.un.org/resources/hrpd/mah/HARDSHIP_XML.xml", "data/hc.json");

function xmlToJson($URL, $TARGET) {
    $url = $URL;
    $xml = simplexml_load_file($url);
    $json = json_encode($xml);

    $target_file = $TARGET;
    $target_file_data = $json;

    $handle = fopen($target_file, "w");
    fwrite($handle, $target_file_data); //write it
    fclose($handle);
}

?>

</body>
</html>


