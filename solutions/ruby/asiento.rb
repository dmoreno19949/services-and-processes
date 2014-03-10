Class Asiento

@ocupado = false
@@asiento= 0

def initialize
    @@asiento += 1
    @asiento = @@asiento
    puts"Soy el asiento #{@asiento}"
end

def ocupar(autobus)
    puts "soy el asiento #{@asiento} del autobus #{@autobus}"
    @ocupado = false
end

def empty?
    @ocupado
end
