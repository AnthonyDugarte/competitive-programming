def handlereps reps, character
    big_reps = (reps / 9).to_i
    small_reps = reps % 9

    print "@" if big_reps > 0 or small_reps > 3

    big_reps.times do
        print "9#{character}"
    end

    if small_reps > 3
        print "#{small_reps}#{character}"
    else
        small_reps.times do
            print character
        end
    end
end

def compress s
    i = 1
    reps = 1
    while i < s.length
        if s[i] == s[i - 1]
            reps += 1
        else
            handlereps reps, s[i - 1]
            reps = 1
        end

        i += 1
    end

    handlereps reps, s[i - 1]
    puts
end

gets.chomp.to_i.times do
    compress gets.chomp
end