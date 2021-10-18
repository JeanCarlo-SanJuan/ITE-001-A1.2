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
            "./problem-1-summation-of-place-value-digits-algorithm-1&2.cpp",
            "./problem-1-summation-of-place-value-digits-algorithm-3.cpp",
            "./problem-2-daily-sales.cpp",
            "./problem-3-Area-of-Rectangle.cpp",
            "./problem-4.cpp",
            "./problem-5.cpp",
            "./problem-6-Class-population.cpp",
            "./problem-7-Volume-of-Object.cpp"
        ];

        foreach($files as $file) {
                $e =  file_get_contents($file);
                echo
                    "<h1>$file</h1>"
                    . "<pre>" 
                        . strval(htmlspecialchars($e)) 
                    . "</pre>";
            }
    ?>
</body>
</html>