#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printdeck(bool flag = true)
{
    FILE *out, *f;
    char ch;
    out = fopen("bin/chess.html", "w");
    setlocale(LC_ALL, "Russian");
    //clang-format off
    fprintf(out,
            R"(<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">)");
    if (flag == true)
        fprintf(out, R"(   <meta http-equiv="Refresh" content="0.5" />
)");
    fprintf(out, R"(   <title>chessviz</title>
  <style type="text/css">
    table.chessboard {
      border: 5px solid #333;
      border-collapse: collapse;
      height: 320px;
      margin: 20px;
      width: 320px;
    }
    table.chessboard caption {
      text-align: left;
    }
    table.chessboard td {
      background-color: #fff;
      font-size: 25px;
      height: 40px;
      text-align: center;
      vertical-align: middle;
      width: 40px;
    }
    table.chessboard tr:nth-child(odd) td:nth-child(even),
    table.chessboard tr:nth-child(even) td:nth-child(odd) {
      background-color: #999;
    }

    table.chessboard .white.king:before   { content: "\2654"; }
    table.chessboard .white.queen:before  { content: "\2655"; }
    table.chessboard .white.rook:before   { content: "\2656"; }
    table.chessboard .white.bishop:before { content: "\2657"; }
    table.chessboard .white.knight:before { content: "\2658"; }
    table.chessboard .white.pawn:before   { content: "\2659"; }

    table.chessboard .black.king:before   { content: "\265A"; }
    table.chessboard .black.queen:before  { content: "\265B"; }
    table.chessboard .black.rook:before   { content: "\265C"; }
    table.chessboard .black.bishop:before { content: "\265D"; }
    table.chessboard .black.knight:before { content: "\265E"; }
    table.chessboard .black.pawn:before   { content: "\265F"; }
  </style>
</head>

<body>
  <table class="chessboard">
)");
    f = fopen("src/figure.txt", "r");
    while ((ch = getc(f)) != EOF)
        fprintf(out, "%c", ch);
    fclose(f);
    fprintf(out,
            R"(</table>
</body>
</html>)");
    fclose(out);
}

void zapoln()
{
    FILE* f;
    f = fopen("src/figure.txt", "w");
    if (f == 0)
        printf("%s",
               "\n\nERROR FILE PATH, TRY GO OUT FROM BIN AND WRITE make\nor "
               "make "
               "start if project already builded");
    else {
        fprintf(f,
                R"(<tr>
      <td><span class="black rook"></span></td>
      <td><span class="black knight"></span></td>
      <td><span class="black bishop"></span></td>
      <td><span class="black queen"></span></td>
      <td><span class="black king"></span></td>
      <td><span class="black bishop"></span></td>
      <td><span class="black knight"></span></td>
      <td><span class="black rook"></span></td>
</tr>
<tr>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
      <td><span class="black pawn"></span></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
</tr>
<tr>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
</tr>
<tr>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
      <td><span class="white pawn"></span></td>
</tr>
<tr>
      <td><span class="white rook"></span></td>
      <td><span class="white knight"></span></td>
      <td><span class="white bishop"></span></td>
      <td><span class="white queen"></span></td>
      <td><span class="white king"></span></td>
      <td><span class="white bishop"></span></td>
      <td><span class="white knight"></span></td>
      <td><span class="white rook"></span></td>
</tr>)");

        fclose(f);
    }
}
//clang-format on
