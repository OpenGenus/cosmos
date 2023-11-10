defmodule Cryptography do
  @baconian_encryption_table %{
    a: "AAAAA",
    b: "AAAAB",
    c: "AAABA",
    d: "AAABB",
    e: "AABAA",
    f: "AABAB",
    g: "AABBA",
    h: "AABBB",
    i: "ABAAA",
    j: "ABAAB",
    k: "ABAAB",
    l: "ABABB",
    m: "ABBAA",
    n: "ABBAB",
    o: "ABBBA",
    p: "ABBBB",
    q: "BAAAA",
    r: "BAAAB",
    s: "BAABA",
    t: "BAABB",
    u: "BABAA",
    v: "BABAB",
    w: "BABBA",
    x: "BABAB",
    y: "BBAAA",
    z: "BBAAB"
  }
  def baconian_encrypt(content) do
    content
    |> String.downcase()
    |> String.split("", trim: true)
    |> Enum.map(&Map.get(@baconian_encryption_table, :"#{&1}", ""))
    |> Enum.join()
  end

  def baconian_decrypt(baconian) do
    baconian_decryption_table =
      Enum.map(@baconian_encryption_table, fn {k, v} -> {v, k} end) |> Enum.into(%{})

    baconian
    |> String.upcase()
    |> String.split("", trim: true)
    |> Enum.chunk_every(5)
    |> Enum.map(fn x ->
      key = Enum.join(x)

      Map.get(baconian_decryption_table, key)
      |> Atom.to_string()
    end)
    |> Enum.join()
  end
end

msg = "Hello world"

Cryptography.baconian_encrypt(msg)
|> IO.inspect(label: "Encrypting #{msg}")
|> Cryptography.baconian_decrypt()
|> IO.inspect(label: "Decrypting encrypted #{msg}")
