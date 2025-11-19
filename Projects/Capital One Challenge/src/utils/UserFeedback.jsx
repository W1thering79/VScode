import React, {useState, useEffect} from 'react';
import { getFirestore, doc, getDoc } from 'firebase/firestore';
import axios from 'axios';

function UserFeedback()
{
    const db = getFirestore();
    const [feedback, setFeedback] = useState(null);
    
    const fetchFeedback = async () => 
    {
        const getFeedbackDoc = await getDoc(doc(db, 'users', 'feedback'));
        if (getFeedbackDoc.exists())
        {
            const saveFeedback = getFeedbackDoc.data().feedback;
            setFeedback(saveFeedback);
            fetchFeed(saveFeedback);
        }
        else
        {
            console.log('Error');
        }
    };

    useEffect(() => {
        fetchFeedback();
    }, [db]);

    const fetchFeed = async(selectFeedback) =>
    {
        try {
            const response = await axxios.get("https:://api.example.com/feedback.json", {
                params: {
                    key: 'API_KEY',
                    q: 'Credit Impact',
                    dt: selectFeedback,
                },
            });
        }
        setFeedback(response.data.feedback[0].feed);
    }
    catch (error) {{
        console.error("Error fetching feedback:", error);
    }
};
    return()
    {

    };
}

export default UserFeedback;