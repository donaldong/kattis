def l;STDIN.readline.chomp;end;F=Hash.new(0);l.to_i.times{F[l]+=1};F.select{|_,v|v==F.values.min}.keys.sort.each{|k|puts k}
