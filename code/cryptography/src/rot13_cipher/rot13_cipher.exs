defmodule Cryptography do
  def rot13(input, n \\ 13) do
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    String.split(input, "", trim: true)
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
              rot > 25 -> rot - 25
              rot < 0 -> rot + 25
              true -> rot
            end

          String.at(alphabet, rot_ind)
        else
          a
        end
    end)
    |> Enum.join("")
  end
end
