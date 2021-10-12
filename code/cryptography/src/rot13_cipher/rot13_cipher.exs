defmodule Cryptography do
  def rot_n(content, n \\ 13) do
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    String.split(content, "", trim: true)
    |> Enum.map(fn
      " " ->
        " "

      a ->
        alphabet_ind =
          String.split(alphabet, "", trim: true)
          |> Enum.find_index(fn x -> x == a end)

        # is letter in the alphabet?
        if is_nil(alphabet_ind) do
          # is not (ex.: has an accent)
          a
        else
          rot = alphabet_ind + n

          rot_parse =
            cond do
              rot > 25 -> rot - 25
              rot < 0 -> rot + 25
              true -> rot
            end

          String.at(alphabet, rot_parse)
        end
    end)
    |> Enum.join()
  end
end
