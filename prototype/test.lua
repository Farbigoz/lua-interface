require "defs"
require "interface"

trc3Gen = interface.trc3Gen
trc3 = interface.trc3Rec
ars = interface.arsGen

mapper = interface.can.mapper
inp = interface.can.input

function b2n(b) return b and 1 or 0 end


function setup()
    trc3[1].level = 99
    trc3[1].carrier = defs.F_720_HZ
    trc3[1].mod = defs.F_8_HZ

    mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}
    mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}

    print("setup done")
end


function loop()
    print("tick")

    ars.gen1.f75 = inp[1]
    ars.gen1.f125 = inp[2]

    trc3Gen.level = trc3Gen.level + 1
    -- print(inp[1])
    -- print(inp[2])
end