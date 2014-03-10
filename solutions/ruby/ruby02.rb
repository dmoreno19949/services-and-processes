#!/usr/bin/env ruby

require 'thread'

require_relative 'autobus'
require_relative 'asiento'

bus = Array.new
sitio = Array.new

rellenar_autobus = Array.new

mutex = Mutex.new

sitios_n = 0


7.times do
	bus << Autobus.new
end


rellenar_autobus << Thread.new
  while(sitios_n < 70) do
     sleep(1)
     mutex.synchronize{
        sitio.push Asiento.new
     }
    alumnos_n += 1
  end

rellenar_autobus.join

puts "hola"

