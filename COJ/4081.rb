correct_input = gets.chomp
users_input = gets.chomp

if correct_input == users_input
    puts "Accepted"
elsif users_input.delete(' ') == correct_input.delete(' ')
    puts "Presentation Error"
else
    puts "Wrong Answer"
end
