states = {}
STDIN.readline
STDIN.each_line do |line|
  action, name = line.split
  if action == "entry"
    print "#{name} entered"
    puts states[name] ? " (ANOMALY)" : ""
    states[name] = true
  else
    print "#{name} exited"
    puts states[name] ? "" : " (ANOMALY)"
    states[name] = false 
  end
end
