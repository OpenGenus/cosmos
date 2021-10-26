defmodule Cryptography do
  # Its rotn, but defaults to rot13
  def rotn(input, n \\ 13) do
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    input
    |> String.downcase()
    |> String.split("", trim: true)
    |> Enum.map(fn
      " " ->
        " "

      a ->
        alphabet_ind =
          String.split(alphabet, "", trim: true) |> Enum.find_index(fn x -> x == a end)

        if !is_nil(alphabet_ind) do
          rot = alphabet_ind + n

          rot_ind =
            cond do
              rot < 0 -> rem(rot, 26) * -1
              true -> rem(rot, 26)
            end

          String.at(alphabet, rot_ind)
        else
          a
        end
    end)
    |> Enum.join("")
  end
end

msg = "Hello world"
n = 13

Cryptography.rotn(msg, n)
|> IO.inspect(label: "Encrypting '#{msg}' in rot#{n}") # uryyb jbeyq
