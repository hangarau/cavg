# Getting started with CAVG

## Finding Your Colours
CAVG is a very simple tool to use. First though, you'll want to identify the two colours you want to average. For this example, I'm going to use the hex codes `0xFF3399` and `0xFF0000`, the rgb codes `rgb(3, 3, 3)` and `rgb(7, 7, 7)`, and the hsl codes `hsl(3, 3, 3)` and `hsl(7, 7, 7)`.

## Averaging Hex Codes

In this example, I'm using the hex codes `0xFF3399` and `0xFF0000` for my two colours. The average of these two is `0xFF19CC`. 

To average a hex code, you can use the `-hc` flag or the `--hex` flag.

Here's how you would use both of them:

```bash
cavg -hc ff3399 ff0000
cavg --hex ff3399 ff0000
```
Obviously, replace the codes with yours.

This command will produce the output:
```plaintext
Average Hex Code: FF19CC
```
This is the average hex code!

## Averaging RGB Codes

In this example, I'm using the rgb codes `rgb(3, 3, 3)` and `rgb(7, 7, 7)` for my two colours. The average of these two is `rgb(5, 5, 5)`. 

To average an rgb code, you can use the `-rgb` flag.

Here's how:

```bash
cavg -rgb 3 3 3 7 7 7
```
Obviously, replace the codes with yours. The format is: `-rgb <r1> <g1> <b1> <r2> <g2> <b2>`

This command will produce the output:
```plaintext
Average RGB Code: rgb( 5, 5, 5,)
```
This is the average RGB code! I know the output format is a bit broken, but this is on my list of things to fix.

## Averaging HSL Codes

In this example, I'm using the hsl codes `hsk(3, 3, 3)` and `hsl(7, 7, 7)` for my two colours. The average of these two is `hsl(5, 5, 5)`. 

To average an rgb code, you can use the `-hsl` flag.

Here's how:

```bash
cavg -hsl 3 3 3 7 7 7
```
Obviously, replace the codes with yours. The format is: `-hsl <h1> <s1> <l1> <h2> <s2> <l2>`

This command will produce the output:
```plaintext
Average HSL Code: hsl( 5, 5, 5,)
```
This is the average HSL code! I know the output format is a bit broken, but this is on my list of things to fix.