<meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1><u>Libraries Included</u></h1>
     <pre style="font-family: 'Courier New', monospace;">
         #include<stdio.h> 
         #include<string.h>
         #include<stdlib.h>
         #include <conio.h> - for getc()
         #include<ctype.h> - to convert alphabets to uppercase or lowercase
        </pre>
    <h1><u>Data Stored</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         account number
         password(encrypted)
         balance
        </pre>
    <h1><u>Creating Account</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         creates .csv file for every account created.(filename as the account number)Stores the data of the structure in the file.
        </pre>
    <h1><u>Asterisk in password</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         uses '\b' to backspace user input and replaces it with '*' and detects enter by its asci value (13).
        </pre>
    <h1><u>Encryption</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         The password is encrypted before storing with a key of +13.
        </pre>
    <h1><u>Login</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         encrypts user input password and compares it with the account number given. To check authentication.
        </pre>
    <h1><u>Transactions</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         Bank Transactions are taken place by accessing csv file data and ammending it.
        </pre>
    <h1><u>Side Note</u></h1>
        <pre style="font-family: 'Courier New', monospace;">
         Functions arent used in the code to keep the simplicity of the code intact.As there would be a lot of passing of varibale if so the case be.
        </pre>
    <br/>
    <h1>Thank You!</h1>
</body>
</html>
