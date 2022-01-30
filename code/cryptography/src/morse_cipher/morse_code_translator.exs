defmodule Cryptography do
  @morse_encryption_table %{
    A: ".-",
    B: "-...",
    C: "-.-.",
    D: "-..",
    E: ".",
    F: "..-.",
    G: "--.",
    H: "....",
    I: "..",
    J: ".---",
    K: "-.-",
    L: ".-..",
    M: "--",
    N: "-.",
    O: "---",
    P: ".--.",
    Q: "--.-",
    R: ".-.",
    S: "...",
    T: "-",
    U: "..-",
    V: "...-",
    W: ".--",
    X: "-..-",
    Y: "-.--",
    Z: "--..",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----.",
    "0": "-----",
    ",": "--..--",
    ".": ".-.-.-",
    "?": "..--..",
    /: "-..-.",
    -: "-....-",
    "(": "-.--.",
    ")": "-.--.-"
  }

  def morse_encrypt(content) do
    content
    |> String.upcase()
    |> String.split("", trim: true)
    |> Enum.map(fn x ->
      @morse_encryption_table[:"#{x}"]
    end)
    |> Enum.join(" ")
  end

  def morse_decrypt(morse) do
    translation_table =
      Enum.map(@morse_encryption_table, fn {k, v} -> {v, k} end)
      |> Enum.into(%{})

    morse
    |> String.split(" ")
    |> Enum.map(fn
      "" ->
        " "

      x ->
        "#{Map.get(translation_table, x)}"
    end)
    |> Enum.join("")
  end
end

msg = "Hello world"

Cryptography.morse_encrypt(msg)
|> IO.inspect(label: "Encrypting #{msg} in morse")
|> Cryptography.morse_decrypt()
|> IO.inspect(label: "Decrypting #{msg}")
