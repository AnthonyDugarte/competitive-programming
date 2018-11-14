$memo = { 1 => 1}

def f n
    return $memo[n] if $memo.has_key?(n)

    if n & 1 == 1
        nn = (n - 1 ) >> 1            
        return $memo[n] = f(nn) + f(nn + 1)
    end

    return $memo[n] = n >> 1
end

val = gets.chomp.to_i

while true
    puts "f(#{ val }) = #{ f val }"

    val = gets.chomp.to_i
    break if val == -1
    puts
end