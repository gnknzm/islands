defmodule Islands do
  def loop(map) when map_size(map) <= 0 do
    IO.puts "席がなくなりました！"
  end

  def loop(map) do
    _ = IO.gets "Enterで島を抽選します"
    map |> reserve_island |> loop
  end

  def reserve_island(map) do
    {island, sheet} = Enum.random(map)
    remaining = sheet - 1
    IO.puts "#{island}に座りましょう 残り#{remaining}席"

    case remaining do
      0 ->
        Map.delete(map, island)
      _ ->
        %{map | island => remaining}
    end
  end
end

Islands.loop(%{"小豆島" => 6, "屋久島" => 6, "種子島" => 6, "軍艦島" => 6, "佐渡島" => 6})
