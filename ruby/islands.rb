islands = {小豆島: 6, 屋久島: 6, 種子島: 6, 軍艦島: 6, 佐渡島: 6}

while islands.length > 0 do
  puts "Enterで島を抽選します"

  line = gets
  island = islands.keys[rand(0..islands.length-1)]
  remaining = islands[island] - 1
  puts "#{island}に座りましょう 残り#{remaining}席"

  if remaining <= 0 then
    islands.delete(island)
  else
    islands[island] = remaining
  end
end

puts "席がなくなりました！"
