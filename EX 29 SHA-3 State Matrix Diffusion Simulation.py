# 5x5 state array: 1 = non-zero lane, 0 = zero lane
rate_lanes = 16  # 1024 bits / 64 bits per lane
state = [1 if i < rate_lanes else 0 for i in range(25)]

print(f"Initial non-zero lanes: {sum(state)} / 25")
rounds = 0

# Simulate diffusion (each round mixes adjacent column and row lanes)
while sum(state) < 25:
    rounds += 1
    new_state = state[:]
    for i in range(25):
        if state[i] == 1:
            # Spread to adjacent row/col neighbors via theta and pi transforms
            new_state[(i + 1) % 25] = 1
            new_state[(i + 5) % 25] = 1
    state = new_state

print(f"Rounds until all capacity lanes have non-zero bits: {rounds}")