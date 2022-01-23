## CORRECCION DE CODIGO EXPLICADO EN CLASE
Luego de realizar la depuración, me di cuenta que la división de SystemCoreClok/1000  o entre 1000000 no genera un resulado correcto
así que se asigna el valor de la división de manera directa.
### Por ejemplo:
Si SYSCLK = 84MHz
- SysTick->LOAD = 84000 - 1;    // para generar retardos de un milisegundo
- SysTick->LOAD = 84-1;         // para generar retardos de un microsegundo

## RESULTADO 

<img src="https://user-images.githubusercontent.com/47931397/150703148-4374ce6d-11e8-4240-8e28-bd5c68a8a7b7.png">

