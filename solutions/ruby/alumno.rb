Class Alumno

@@alumno = 0

def initialize
 	@@alumno += 1
	@alumno = @@alumno
	puts "Alumno #{@alumno} creado"
end
