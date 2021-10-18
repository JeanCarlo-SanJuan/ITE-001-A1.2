<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            font-size: 14px;
            font-family: arial;
            margin: 2vh 2vw;
        }
    </style>
</head>
<body>
    <?php
        $files = [
            "./problem-1-Volume-of-Sphere.cpp",
            "./problem-2-Celcius-to-Fahrenheit-Converter.cpp",
            "./problem-3-Heron's-formula.cpp",
            "./problem-4-Circumference-formula.cpp",
            "./problem-5-Depreciation-Formula.cpp",
            "./problem-6-Perfect-Cube.cpp",
            "./problem-7-Economic-Order-Quantity.cpp",
            "./problem-8-Kilogram-to-Pounds-Converter.cpp"
        ];

        foreach($files as $file) {
                $e =  file_get_contents($file);
                echo
                    "<h2>$file</h2>"
                    . "<pre>" 
                        . strval(htmlspecialchars($e)) 
                    . "</pre>";
            }
    ?>
</body>
</html>