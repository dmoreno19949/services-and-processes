class Autobus

@@bus = 0 

def initialize
   @@bus += 1
   @bus = @@bus
   puts "Autobus #{@bus} creado" 
end


end
