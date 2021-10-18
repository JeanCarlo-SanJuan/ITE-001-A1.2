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
            "Problem 1 - Algorithm 1 & 2" => "problem-1-summation-of-place-value-digits-algorithm-1&2.cpp",
            "Problem 1 - Algorithm 3" => "problem-1-summation-of-place-value-digits-algorithm-3.cpp",
            "Problem 2" => "problem-2-daily-sales.cpp",
            "Problem 3" => "problem-3-Area-of-Rectangle.cpp",
            "Problem 4" => "problem-4-Credit-Card-Interest.cpp",
            "Problem 5" => "problem-5.cpp",
            "Problem 6" => "problem-6-Class-population.cpp",
            "Problem 7" => "problem-7-Volume-of-Object.cpp"
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