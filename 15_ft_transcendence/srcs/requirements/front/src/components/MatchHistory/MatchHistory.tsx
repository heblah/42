import React, { useEffect, useState } from 'react';
import axios from 'axios';
import './MatchHistory.scss';

interface GameSessionOutcome {
  Player1Name: string;
  Player2Name: string;
  winnerName: string;
  loserName: string;
}

interface MatchHistoryProps {
  userID: number;
  token: string; 
}

const MatchHistory: React.FC<MatchHistoryProps> = ({ userID, token }) => {
  const [gameSessionOutcome, setGameSessionOutcome] = useState<GameSessionOutcome[]>([]);

  useEffect(() => {
    const fetchMatchHistory = async () => {
      try {
        const res = await axios.post('http://localhost:8080/search/user-match-history', { id: userID }, { 
            headers: { 'Authorization': `Bearer ${token}` 
            }
        });
        setGameSessionOutcome(res.data);
      } catch (err) {
        console.error(err);
      }
    };
    fetchMatchHistory();
  }, [userID, token]);
 
  return (
    <div className='display-match-history'>
      {gameSessionOutcome.length ?
      ( gameSessionOutcome.map((outcome, index) => (
        <div className='match-history-cell' key={index}>
          <p>{outcome.Player1Name} VS {outcome.Player2Name} || Winner &#9989; {outcome.winnerName} Loser &#x274C; {outcome.loserName}</p>
        </div>))
      ) : <div className='display-match-no-history'>You have no match in your history</div>
      }
    </div>
  );
  
};

export default MatchHistory;
