require "defs"
require "interface"

ktrc = interface.mu.ktrc

mapper = interface.can.mapper
inp = interface.can.input


function b2n(b) return b and 1 or 0 end     -- bool to num
function n2b(n) return n ~= 0 end           -- num to bool


function setup()
    -- Конфигурирование маппера CAN сообщений
    mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}     -- РЦ 1
    mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}     -- РЦ 2

    print("setup done")
end



function loop()
    print("tick")

    -- Управление кодированием первого КТРЦ
    ktrc[0].arsGen[1].f75 = inp[1]
    ktrc[0].arsGen[1].f125 = not n2b(inp[2])

    -- Текущее время в миллисекундах (время с момента запуска)
    time = interface.time()
end







require "interface"

ktrc = interface.mu.ktrc

ktrc[0].arsGen.level.f75 = 90
ktrc[0].arsGen.level.f125 = 95
ktrc[0].arsGen.level.f175 = 100
ktrc[0].arsGen.level.f225 = 105
ktrc[0].arsGen.level.f275 = 110
ktrc[0].arsGen.level.f325 = 115
ktrc[0].arsGen.level.f275_ao = 120

ktrc[1].arsGen.level.f75 = 91
ktrc[1].arsGen.level.f125 = 96
ktrc[1].arsGen.level.f175 = 101
ktrc[1].arsGen.level.f225 = 106
ktrc[1].arsGen.level.f275 = 111
ktrc[1].arsGen.level.f325 = 116
ktrc[1].arsGen.level.f275_ao = 121

ktrc[2].arsGen.level.f75 = 92
ktrc[2].arsGen.level.f125 = 97
ktrc[2].arsGen.level.f175 = 102
ktrc[2].arsGen.level.f225 = 107
ktrc[2].arsGen.level.f275 = 112
ktrc[2].arsGen.level.f325 = 117
ktrc[2].arsGen.level.f275_ao = 122

function print_arsGen(_arsGen)
    print("\tarsGen.level.f75:", _arsGen.level.f75)
    print("\tarsGen.level.f75:", _arsGen.level.f125)
    print("\tarsGen.level.f75:", _arsGen.level.f175)
    print("\tarsGen.level.f75:", _arsGen.level.f225)
    print("\tarsGen.level.f75:", _arsGen.level.f275)
    print("\tarsGen.level.f75:", _arsGen.level.f325)
    print("\tarsGen.level.f75:", _arsGen.level.f275_ao)
    print()
    print("\tarsGen[1].f75:   ", _arsGen[1].f75)
    print("\tarsGen[1].f75:   ", _arsGen[1].f125)
    print("\tarsGen[1].f75:   ", _arsGen[1].f175)
    print("\tarsGen[1].f75:   ", _arsGen[1].f225)
    print("\tarsGen[1].f75:   ", _arsGen[1].f275)
    print("\tarsGen[1].f75:   ", _arsGen[1].f325)
    print("\tarsGen[1].f75:   ", _arsGen[1].f275_ao)
    print()
    print("\tarsGen[2].f75:   ", _arsGen[2].f75)
    print("\tarsGen[2].f75:   ", _arsGen[2].f125)
    print("\tarsGen[2].f75:   ", _arsGen[2].f175)
    print("\tarsGen[2].f75:   ", _arsGen[2].f225)
    print("\tarsGen[2].f75:   ", _arsGen[2].f275)
    print("\tarsGen[2].f75:   ", _arsGen[2].f325)
    print("\tarsGen[2].f75:   ", _arsGen[2].f275_ao)
end