use rand::Rng;

struct Island {
    name: String,
    seats: i32,
}

impl Island {
    fn new(name: &str, seats: i32) -> Island {
        Island{
            name: name.to_string(),
            seats: seats,
        }
    }

    fn take_seat(&mut self) {
        self.seats = self.seats - 1;
    }
}

fn main() {
    let mut islands = vec![Island::new("小豆島", 6),
                       Island::new("屋久島", 6),
                       Island::new("種子島", 6),
                       Island::new("軍艦島", 6),
                       Island::new("佐渡島", 6)];
    let mut rng = rand::thread_rng();

    loop {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).ok();

        let rn = rng.gen_range(0, islands.len());
        islands[rn].take_seat();
        println!("{}に座りましょう！ 残り{}席です", islands[rn].name, islands[rn].seats);

        if islands[rn].seats <= 0 {
            islands.swap_remove(rn);
            if islands.len() <= 0 {
                println!("席がなくなりました！");
                break;
            }
        }
    }
}