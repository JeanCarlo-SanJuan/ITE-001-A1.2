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
            "Problem 1" => "problem-1-Volume-of-Sphere.cpp",
            "Problem 2" => "problem-2-Celcius-to-Fahrenheit-Converter.cpp",
            "Problem 3" => "problem-3-Heron's-formula.cpp",
            "Problem 4" => "problem-4-Circumference-formula.cpp",
            "Problem 5" => "problem-5-Depreciation-Formula.cpp",
            "Problem 6" => "problem-6-Perfect-Cube.cpp",
            "Problem 7" => "problem-7-Economic-Order-Quantity.cpp",
            "Problem 8" => "problem-8-Kilogram-to-Pounds-Converter.cpp"
        ];

        foreach($files as $title => $file) {
            echo
                "<section>
                    <h1>$title</h1>
                    <h2>Filename: $file</h2>"
                    . "<pre>" 
                        . strval(htmlspecialchars( file_get_contents($file) )) 
                    . "</pre>
                </section>";
        }
    ?>
</body>
</html>