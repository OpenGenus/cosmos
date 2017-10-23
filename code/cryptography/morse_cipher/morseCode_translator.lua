-- Lua code to convert text to morse code // tested on Lua 5.3.3

function enc(message)
  -- Lua dictionary containing the morse alphabets
  change = {
    A = ".-", B = "-...", C = "-.-.", D = "-..", E = ".",
    F = "..-.", G = "--.", H = "....", I = "..", J = ".---",
    K = "-.-", L = ".-..", M = "--", N = "-.", O = "---",
    P = ".--.", Q = "--.-", R = ".-.", S = "...", T = "-",
    U = "..-", V = "...-", W = ".--", X = "-..-", Y = "-.--",
    Z = "--..", [1]=".----", [2]="..---", [3]="...--",
    [4]="....-", [5]=".....", [6]="-....", [7]="--...",
    [8]="---..", [9]="----.", [0]="-----"
  }
  cipherText = ""
  for i=1, string.len(message) do
    -- (s.sub(s, i, i))
    str = string.sub(message, i, i)
    if str ~= " " then
      -- one space after every letter
      cipherText = cipherText .. change[str] .. " "
    else
      -- two spaces after every word
      cipherText = cipherText .. "  "
    end
  end
  -- print the final cipher text
  print(cipherText)
end
-- user input from STDIN
str = io.read()
-- calling main translation function
enc(str)
