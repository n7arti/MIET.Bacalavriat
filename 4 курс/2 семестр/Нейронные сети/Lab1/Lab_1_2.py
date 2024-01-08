# Нейронные сети 
# Лабораторная работа 1
# Программа вычисления ДПФ гармонического сигнала

import numpy as np
import matplotlib.pyplot as plt

print('*** Программа вычисления ДПФ гармонического сигнала ***')
A = float(input('Введите амплитуду сигнала, ед.: '))
f0 = float(input('Введите частоту сигнала, Гц: '))

fdn = 2 * f0  # Частота дискретизации
# в соответствии с критерием Найквиста
mvis = 4
fdv = mvis * fdn  # Частота дискретизации для визуализации
dt = 1 / fdv  # Интервал дискретизации по времени
T = 1 / f0  # Период сигнала
NT = 6
t = np.arange(0, NT * T, dt)  # Вектор времени, с
y = A * np.sin(2 * np.pi * f0 * t)
# Вектор сигнала
N = len(y)

# Дискретное преобразование Фурье
k = np.arange(N)
Ex = np.exp(-1j * 2 * np.pi / N * np.transpose(k) * k)
Y = y * Ex

# Обратное дискретное преобразование Фурье
Ex = np.exp(1j * 2 * np.pi / N * np.transpose(k) * k)
ys = Y / (N - 1) * Ex

Y2 = Y * np.conj(Y)  # Квадрат модулЯ Фурье-образа
ff = k * fdv / N  # Вектор частоты, Гц

plt.figure(1)
plt.plot(ff, Y2, 'r')
plt.xlabel('Frequency, Hz')
plt.ylabel('Fourier-image modulus squared')
plt.figure(2)
plt.subplot(2, 2, 1)
plt.plot(t, np.real(y), 'r')
plt.axis([0, NT * T, -1.1 * A, 1.1 * A])
plt.title('Real part')
plt.xlabel('Time, s')
plt.ylabel('Initial signal')
plt.subplot(2, 2, 2)
plt.plot(t, np.imag(y), 'b')
plt.axis([0, NT * T, -1.1 * A, 1.1 * A])
plt.title('Imaginary part')
plt.xlabel('Time, s')
plt.ylabel('Initial signal')
plt.subplot(2, 2, 3)
plt.plot(t, np.real(ys), 'r')
plt.axis([0, NT * T, -1.1 * A, 1.1 * A])
plt.xlabel('Time, s')
plt.ylabel('Restored signal')
plt.subplot(2, 2, 4)
plt.plot(t, np.imag(ys), 'b')
plt.axis([0, NT * T, -1.1 * A, 1.1 * A])
plt.xlabel('Time, s')
plt.ylabel('Restored signal')
plt.show()

print('**********   Конец работы   **********')
