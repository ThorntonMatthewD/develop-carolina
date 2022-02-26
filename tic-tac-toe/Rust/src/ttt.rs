//My first Rust program :^)

fn display_board(board: &[char]) {

    let size = board.len();

    println!("-------------");

    for i in (0..size).step_by(3) {
        println!("| {} | {} | {} |", board[i], board[i + 1], board[i + 2]);
        println!("-------------");
    }
}


fn reset_board(board: &mut [char]) {
    for i in 0..board.len() {
        board[i] = '-';
    }
}


fn place_marker(board: &mut [char], player: char) {
    loop {
        let mut input_num = String::new();

        println!("Select a tile (1-8) to place your marker: ");

        if std::io::stdin().read_line(&mut input_num).is_err() {
            println!("Try not entering garbage next time.");
            continue;
        }

        if let Ok(number) = input_num.trim().parse::<usize>() {
            if number > 8 {
                println!("{} needs to be between 0 and 8.", number);
                continue;
            }

            if board[number] != '-' {
                println!("There is an {} marker already on tile {}. Select another.", board[number], number);
            }

            board[number] = player;

            break;
        } else {
            println!("ENTER A NUMBER!!!!!!!!! 0-8!!!! It's not that difficult!!!");
            continue;
        }
    }
}


fn check_for_win(board: &[char]) -> bool {
    //Diagonal win check
    if board[4] != '-' {
        if board[0] == board[4] && board[4] == board[8] {
            return true;
        } else if board[2] == board[4] && board[4] == board[6] {
            return true;
        } else {
            //No diagonal win! Keep looking.
        }
    }

    //Horizontal win check
    let h_depends: [usize;3] = [1,4,7];
    
    for i in h_depends{
        if board[i - 1] == board[i] && board[i] == board[i + 1] && board[i] != '-' {
            return true;
        }
    }

    //Vertical win check
    let v_depends: [usize;3] = [3,4,5];

    for i in v_depends {
        if board[i - 3] == board[i] && board[i] == board[i + 3] && board[i] != '-' {
            return true;
        }
    }

    false
}


fn keep_playing_check(turn_count: &mut i8) -> bool {

    let mut response = String::new();

    println!("Enter Y to play again. Enter literally anything else to stop playing: ");

    if std::io::stdin().read_line(&mut response).is_err() {
        //bad input, oh well. just end the game.
    } else {
        let char_vec: Vec<char> = response.chars().collect();

        if char_vec[0] == 'Y' || char_vec[0] == 'y' {
            *turn_count = 1;
            return true;
        } 
    }

    println!("Thanks for playing!");
    return false;
}


fn main() {
    let mut board: [char; 9] = ['-', '-', '-', '-', '-', '-', '-', '-', '-'];

    let mut keep_playing = true;
    let mut player = 'X';
    let mut turn_count : i8 = 1;

    reset_board(&mut board);


    while keep_playing {
        display_board(&board);

        //Prompt user for marker location and place it if it's clear
        place_marker(&mut board, player);

        if turn_count == 9 {
            if check_for_win(&board) {
                println!("Congratulations Player {}! You've won!!", player);
                display_board(&board);
                keep_playing = keep_playing_check(&mut turn_count);
                //How do I run reset_board from within keep_playing_check and pass the board by reference twice????
                if keep_playing {
                    reset_board(&mut board);
                }
            } else {
                println!("Looks like we have a tie on our hands. In others words, you both lose! Yay!");
                keep_playing = keep_playing_check(&mut turn_count);
                if keep_playing {
                    reset_board(&mut board);
                }
            }
        } else if turn_count >= 5 {
            if check_for_win(&board) {
                println!("Congratulations Player {}! You've won!!", player);
                display_board(&board);
                keep_playing = keep_playing_check(&mut turn_count);
                if keep_playing {
                    reset_board(&mut board);
                }
            } else {
                turn_count = turn_count + 1;
            }
        } else {
            turn_count = turn_count + 1;
        }

        player = if player == 'X' { 'O' } else { 'X' }
    }
}
