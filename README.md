testAlarmaB-sico
================

Este repositorio contiene el código necesario para la implementación de un ejercicio teórico con arduino yun.
Sus fines son puramente académicos y didacticos.

Descripción del entorno
=======================

La sucursal 2741 de la entidad bancaria Santander, cuenta al igual que sus homólogos en el resto del territorio nacional con varias mesas y mostradores que conforman los puestos de trabajos de sus empleados, así como con una caja fuerte donde se guarda todo el efectivo de la entidad.
Para proteger todos los bienes materiales y humanos, la entidad cuenta con pulsadores de atraco silenciosos que avisan a la CRA (Central Receptora de Alarmas) y un contacto magnético tipo lapa en la puerta de la caja fuerte.

Comportamiento del Sistema
==========================
*Armar Sistema: A + intro
*Desarmar Sistema: D + intro
*Silenciar Alarmas: S + intro
*Rearmar Sistema: R + intro

Sistema Desarmado
=================
Cuando el sistema esté desarmado solo seguirán en funcionamiento los pulsadores de atraco y la comunicación con la CRA. (siempre están activos)

Sistema Armado
==============
Si el sistema se arma cualquier evento anormal en las zonas supervisadas generarán una alarma. Además el sistema sigue manteniendo activas alas comunicaciones y los pulsadores.

Alarma
======
Cuando se produzca una alarma por alguna de las zonas supervisadas (A0 -A5) como puede ser el magnético de la caja fuerte se activaran tanto la sirena lumínica como sonora y un relé que enciende todas las luces de la entidad.

Si la alarma es silenciosa (pulsadores de atraco o pánico) solo se enciende las sirenas o indicadores luminosos.

Itinerario del Caso
08:30 - Abre la sucursal y el director de la misma accede a su despacho y comienza con sus labores rutinarias de trabajo.
10:20 - El día transcurre como cualquier otro día normal.
11:30 - Entra un ladrón al banco y amenaza al director de la entidad con un arma. Pide que se le entregue el dinero de la caja fuerte.
- La cajera presiona el botón de "pánico - atraco" inmediatamente tras ver la situación.
11:31 - El vigilante de la CRA visualiza la alarma silenciosa de atraco y notifica inmediatamente a las fuerzas del orden.
11:33 - Las sirenas de la policía alertan al ladrón de la inminente llegada y este sale corriendo despavorido.
14:30 - Se cierra la oficina para contar el dinero.
14:31 - El director de la entidad llama a la CRA para que desactiven la alarma y proceder al recuento.
14:32 - Se desactiva la alarma.
14:40 - Se llama a la CRA para que se arme la alarma.
14:41 - Todos se marchan.
22:50 - El ladrón regresa a la oficina, hace un agujero en el cristal y accede a la misma.
22:51 - El ladrón accede a la habitación de la caja fuerte.
23:15 - El ladrón corta las bisagras de la caja y manipula los cables del magnético para cortocircuitarlos y simular un estado normal. 
23:15 - Salta la alarma( suena la sirena) y se enciende las luces de toda la entidad.
23:15 - El vigilante de la CRA visualiza la alarma y avisa a la policía.
23:16 - El ladrón sale huyendo y es capturado unas calles más adelante.
23:18 - Se rearma el sistema y se precinta la entidad.
