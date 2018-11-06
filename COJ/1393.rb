a, b = gets.chop.split(' ').map{|e| e.to_i }

str = (a ** b).to_s

while str.size > 70 do 
    puts str[0..69]
    str = str[70..-1]
end

puts str