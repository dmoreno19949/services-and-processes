#!/usr/bin/env ruby

require 'thread'

x = 0

mutex_de = Mutex.new

hilo[]

Thread.new do
    while x<6
	x += 1
	hilo.push x	
	sleep(1)
    end
   end


hilo.each |l| do
 put "contenido del hilo 1 :  #{l}"
 sleep(1);
end



