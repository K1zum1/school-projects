"""Visualizing Twitter Sentiment Across America"""

from data import word_sentiments, load_tweets
from datetime import datetime
from geo import us_states, geo_distance, make_position, longitude, latitude
from maps import draw_state, draw_name, draw_dot, wait
from string import ascii_letters
from ucb import main, trace, interact, log_current_line


###################################
# Phase 1: The Feelings in Tweets #
###################################

# The tweet abstract data type, implemented as a dictionary.

def make_tweet(text, time, lat, lon):
    """Return a tweet, represented as a Python dictionary.

    text  -- A string; the text of the tweet, all in lowercase
    time  -- A datetime object; the time that the tweet was posted
    lat   -- A number; the latitude of the tweet's location
    lon   -- A number; the longitude of the tweet's location

    >>> t = make_tweet("just ate lunch", datetime(2012, 9, 24, 13), 38, 74)
    >>> tweet_text(t)
    'just ate lunch'
    >>> tweet_time(t)
    datetime.datetime(2012, 9, 24, 13, 0)
    >>> p = tweet_location(t)
    >>> latitude(p)
    38
    >>> tweet_string(t)
    '"just ate lunch" @ (38, 74)'
    """
    return {'text': text, 'time': time, 'latitude': lat, 'longitude': lon}

def tweet_text(tweet):
    """Return a string, the words in the text of a tweet."""
    "*** YOUR CODE HERE ***"
    # access the key 'text' in the dictionary
    return tweet['text']

def tweet_time(tweet):
    """Return the datetime representing when a tweet was posted."""
    "*** YOUR CODE HERE ***"
    # access the key 'time' in the dictionary
    return tweet['time']

def tweet_location(tweet):
    """Return a position representing a tweet's location."""
    "*** YOUR CODE HERE ***"
    # acess the key 'latitude' and 'longitude' in the dictionary
    return make_position(tweet['latitude'],tweet['longitude'])

# The tweet abstract data type, implemented as a function.

def make_tweet_fn(text, time, lat, lon):
    """An alternate implementation of make_tweet: a tweet is a function.

    >>> t = make_tweet_fn("just ate lunch", datetime(2012, 9, 24, 13), 38, 74)
    >>> tweet_text_fn(t)
    'just ate lunch'
    >>> tweet_time_fn(t)
    datetime.datetime(2012, 9, 24, 13, 0)
    >>> latitude(tweet_location_fn(t))
    38
    """
    "*** YOUR CODE HERE ***"
    # Please don't call make_tweet in your solution
    # make a helper function that takes in a key and returns the value
    def make_tweet_fn_k(key):
        # if key = 'text' return text
        if key == 'text':
            return text
        # if key = 'time' return time
        elif key == 'time':
            return time
        # if key = 'lat' return lat
        elif key == 'lat':
            return lat
        # if key = 'lon' return lon
        elif key == 'lon':
            return lon
    # return the helper function when called
    return make_tweet_fn_k

def tweet_text_fn(tweet):
    """Return a string, the words in the text of a functional tweet."""
    # call the helper function with the key 'text'
    return tweet('text')

def tweet_time_fn(tweet):
    """Return the datetime representing when a functional tweet was posted."""
    #  call the helper function with the key 'time'
    return tweet('time')

def tweet_location_fn(tweet):
    """Return a position representing a functional tweet's location."""
    # call the helper function with the key 'lat' and 'lon'
    return make_position(tweet('lat'), tweet('lon'))

### === +++ ABSTRACTION BARRIER +++ === ###

def tweet_words(tweet):
    """Return the words in a tweet."""
    return extract_words(tweet_text(tweet))

def tweet_string(tweet):
    """Return a string representing a functional tweet."""
    location = tweet_location(tweet)
    point = (latitude(location), longitude(location))
    return '"{0}" @ {1}'.format(tweet_text(tweet), point)

def extract_words(text):
    """Return the words in a tweet, not including punctuation.

    >>> extract_words('anything else.....not my job')
    ['anything', 'else', 'not', 'my', 'job']
    >>> extract_words('i love my job. #winning')
    ['i', 'love', 'my', 'job', 'winning']
    >>> extract_words('make justin # 1 by tweeting #vma #justinbieber :)')
    ['make', 'justin', 'by', 'tweeting', 'vma', 'justinbieber']
    >>> extract_words("paperclips! they're so awesome, cool, & useful!")
    ['paperclips', 'they', 're', 'so', 'awesome', 'cool', 'useful']
    >>> extract_words('@(cat$.on^#$my&@keyboard***@#*')
    ['cat', 'on', 'my', 'keyboard']
    """
    "*** YOUR CODE HERE ***"
    # create an empty list
    listText = []
    # iterate x through the list of text
    for x in list(text):
        # if x is in ascii_letters, append x to the list
        if x in ascii_letters:
            listText.append(x)
        # otherwise append a space instead
        else:
            listText.append(' ')
    # join the list together and return the split text
    text = ''.join(listText)
    return text.split()




def make_sentiment(value):
    """Return a sentiment, which represents a value that may not exist.

    >>> positive = make_sentiment(0.2)
    >>> neutral = make_sentiment(0)
    >>> unknown = make_sentiment(None)
    >>> has_sentiment(positive)
    True
    >>> has_sentiment(neutral)
    True
    >>> has_sentiment(unknown)
    False
    >>> sentiment_value(positive)
    0.2
    >>> sentiment_value(neutral)
    0
    """
    assert value is None or (value >= -1 and value <= 1), 'Illegal value'
    "*** YOUR CODE HERE ***"
    # return the value from the assertion
    return value

def has_sentiment(s):
    """Return whether sentiment s has a value."""
    "*** YOUR CODE HERE ***"
    # return true if s is not None
    return s != None
def sentiment_value(s):
    """Return the value of a sentiment s."""
    assert has_sentiment(s), 'No sentiment value'
    "*** YOUR CODE HERE ***"
    # return s
    return s

def get_word_sentiment(word):
    """Return a sentiment representing the degree of positive or negative
    feeling in the given word.

    >>> sentiment_value(get_word_sentiment('good'))
    0.875
    >>> sentiment_value(get_word_sentiment('bad'))
    -0.625
    >>> sentiment_value(get_word_sentiment('winning'))
    0.5
    >>> has_sentiment(get_word_sentiment('Berkeley'))
    False
    """
    # Learn more: http://docs.python.org/3/library/stdtypes.html#dict.get
    return make_sentiment(word_sentiments.get(word))

def analyze_tweet_sentiment(tweet):
    """ Return a sentiment representing the degree of positive or negative
    sentiment in the given tweet, averaging over all the words in the tweet
    that have a sentiment value.

    If no words in the tweet have a sentiment value, return
    make_sentiment(None).

    >>> positive = make_tweet('i love my job. #winning', None, 0, 0)
    >>> round(sentiment_value(analyze_tweet_sentiment(positive)), 5)
    0.29167
    >>> negative = make_tweet("saying, 'i hate my job'", None, 0, 0)
    >>> sentiment_value(analyze_tweet_sentiment(negative))
    -0.25
    >>> no_sentiment = make_tweet("berkeley golden bears!", None, 0, 0)
    >>> has_sentiment(analyze_tweet_sentiment(no_sentiment))
    False
    """
    # You may change any of the lines below.
    average = make_sentiment(None)

    "*** YOUR CODE HERE ***"
    word = tweet_words(tweet)
    totalwords = 0
    counter = 0

    # iterate x through the list of words
    for x in word:
        # if the word has a sentiment value, add the sentiment value to the totalwords
        if has_sentiment(get_word_sentiment(x)):
            # add the value to totalwords
            totalwords += sentiment_value(get_word_sentiment(x))
            # increment the counter by 1
            counter += 1
    # if the counter is 0, return the average or return the average of the totalwords divided by the counter
    if counter == 0:
        return average
    else:
        return make_sentiment(totalwords / counter)


#################################
# Phase 2: The Geometry of Maps #
#################################

def find_centroid(polygon):
    """Find the centroid of a polygon.

    http://en.wikipedia.org/wiki/Centroid#Centroid_of_polygon

    polygon -- A list of positions, in which the first and last are the same

    Returns: 3 numbers; centroid latitude, centroid longitude, and polygon area

    Hint: If a polygon has 0 area, use the latitude and longitude of its first
    position as its centroid.

    >>> p1, p2, p3 = make_position(1, 2), make_position(3, 4), make_position(5, 0)
    >>> triangle = [p1, p2, p3, p1]  # First vertex is also the last vertex
    >>> round5 = lambda x: round(x, 5) # Rounds floats to 5 digits
    >>> tuple(map(round5, find_centroid(triangle)))
    (3.0, 2.0, 6.0)
    >>> tuple(map(round5, find_centroid([p1, p3, p2, p1])))
    (3.0, 2.0, 6.0)
    >>> tuple(map(float, find_centroid([p1, p2, p1])))  # A zero-area polygon
    (1.0, 2.0, 0.0)
    """
    "*** YOUR CODE HERE ***"
    # initialize the variables needed
    polygonArea, centroidLatitude, centroidLongitude, xcount = 0,0,0,0
    # get the length of the polygon
    n = (len(polygon) - 1)
    
    # while xcount is less than the length of the polygon
    while xcount < n:
        # get the latitude and longitude of the polygon and set to x and y
        x, y = latitude(polygon[xcount]), longitude(polygon[xcount])
        # get the latitude and longitude of the polygon and set to xx and yy
        xx, yy = latitude(polygon[xcount + 1]), longitude(polygon[xcount + 1])
        # calculate the polygon area, centroid latitude, and centroid longitude 
        polygonArea += x*yy - xx*y
        centroidLatitude += (x + xx) * (x*yy - xx*y)
        centroidLongitude += (y + yy) * (x*yy - xx*y) 
        # increment xcount by 1
        xcount += 1

    # divide the polygon area by 2 
    polygonArea = polygonArea / 2
    # if it happens to be 0 then return the latitude and longitude of the polygon and the polygon area
    if polygonArea == 0:
        return latitude(polygon[0]), longitude(polygon[0]), polygonArea
    
    # divide the centroid latitude and centroid longitude by 6 times the polygon area
    centroidLatitude = centroidLatitude / (6 * polygonArea)
    centroidLongitude = centroidLongitude / (6 * polygonArea)
    # return final results and the absolute value of the polygon area because it is negative sometimes
    return centroidLatitude, centroidLongitude, abs(polygonArea)

def find_state_center(polygons):
    """Compute the geographic center of a state, averaged over its polygons.

    The center is the average position of centroids of the polygons in polygons,
    weighted by the area of those polygons.

    Arguments:
    polygons -- a list of polygons

    >>> ca = find_state_center(us_states['CA'])  # California
    >>> round(latitude(ca), 5)
    37.25389
    >>> round(longitude(ca), 5)
    -119.61439

    >>> hi = find_state_center(us_states['HI'])  # Hawaii
    >>> round(latitude(hi), 5)
    20.1489
    >>> round(longitude(hi), 5)
    -156.21763
    """
    "*** YOUR CODE HERE ***"
    # initialize the variables needed
    latitude, longitude, totalArea = 0, 0, 0

    # iterate x through the list of polygons
    for x in polygons:
        # get the centroid of the polygon and set to i
        i = find_centroid(x)[2]
        # calculate the latitude, longitude, and total area
        latitude += find_centroid(x)[0] * i
        longitude += find_centroid(x)[1] * i
        totalArea += i
    
    # divide the latitude and longitude by the total area and return the final results
    lat = latitude / totalArea
    lon = longitude / totalArea

    return make_position(lat,lon)

###################################
# Phase 3: The Mood of the Nation #
###################################

def group_tweets_by_state(tweets):
    """Return a dictionary that aggregates tweets by their nearest state center.

    The keys of the returned dictionary are state names, and the values are
    lists of tweets that appear closer to that state center than any other.

    tweets -- a sequence of tweet abstract data types

    >>> sf = make_tweet("welcome to san francisco", None, 38, -122)
    >>> ny = make_tweet("welcome to new york", None, 41, -74)
    >>> two_tweets_by_state = group_tweets_by_state([sf, ny])
    >>> len(two_tweets_by_state)
    2
    >>> california_tweets = two_tweets_by_state['CA']
    >>> len(california_tweets)
    1
    >>> tweet_string(california_tweets[0])
    '"welcome to san francisco" @ (38, -122)'
    """
    tweets_by_state = {}
    "*** YOUR CODE HERE ***"
    # iterate x through the list of tweets
    for x in tweets:
        # get lat and lon by calling tweet_location
        lat = latitude(tweet_location(x))
        lon = longitude(tweet_location(x))
        # set tweet to the lat and lon and set distance to a large number
        tweet = make_position(lat, lon)
        distance =  1000000000000000
        state = None
        # iterate y through the list of us_states
        for y in us_states:
            # if the distance between the tweet and the state center is less than the distance
            if geo_distance(tweet, find_state_center(us_states[y])) < distance:
                # set the distance to the new distance and set the state to the state
                distance = geo_distance(tweet, find_state_center(us_states[y]))
                state = y
        # if the state is already in the dictionary then append the tweet to the list
        if state in tweets_by_state:
            tweets_by_state[state].append(x)
        else:
            # else create a new list with the tweet and return the dictionary
            tweets_by_state[state] = [x]
    return tweets_by_state

def average_sentiments(tweets_by_state):
    """Calculate the average sentiment of the states by averaging over all
    the tweets from each state. Return the result as a dictionary from state
    names to average sentiment values (numbers).

    If a state has no tweets with sentiment values, leave it out of the
    dictionary entirely.  Do NOT include states with no tweets, or with tweets
    that have no sentiment, as 0.  0 represents neutral sentiment, not unknown
    sentiment.

    tweets_by_state -- A dictionary from state names to lists of tweets
    """
    averaged_state_sentiments = {}
    "*** YOUR CODE HERE ***"
    # iterate x through the list of tweets by state
    for x in tweets_by_state:
        total = 0
        count = 0
        # iterate y through the list of tweets by state
        for y in tweets_by_state[x]:
            # if the tweet has a sentiment then add the sentiment value to the total and increment count by 1
            if has_sentiment(analyze_tweet_sentiment(y)):
                total += sentiment_value(analyze_tweet_sentiment(y))
                count += 1
        # if count is not 0 
        if count != 0:
            # then we can calculate the average sentiment and add it to the dictionary
            averaged_state_sentiments[x] = total / count       
    # return the dictionary
    return averaged_state_sentiments


##########################
# Command Line Interface #
##########################

def print_sentiment(text='Are you virtuous or verminous?'):
    """Print the words in text, annotated by their sentiment scores."""
    words = extract_words(text.lower())
    layout = '{0:>' + str(len(max(words, key=len))) + '}: {1:+}'
    for word in words:
        s = get_word_sentiment(word)
        if has_sentiment(s):
            print(layout.format(word, sentiment_value(s)))

def draw_centered_map(center_state='TX', n=10):
    """Draw the n states closest to center_state."""
    us_centers = {n: find_state_center(s) for n, s in us_states.items()}
    center = us_centers[center_state.upper()]
    dist_from_center = lambda name: geo_distance(center, us_centers[name])
    for name in sorted(us_states.keys(), key=dist_from_center)[:int(n)]:
        draw_state(us_states[name])
        draw_name(name, us_centers[name])
    draw_dot(center, 1, 10)  # Mark the center state with a red dot
    wait()

def draw_state_sentiments(state_sentiments):
    """Draw all U.S. states in colors corresponding to their sentiment value.

    Unknown state names are ignored; states without values are colored grey.

    state_sentiments -- A dictionary from state strings to sentiment values
    """
    for name, shapes in us_states.items():
        sentiment = state_sentiments.get(name, None)
        draw_state(shapes, sentiment)
    for name, shapes in us_states.items():
        center = find_state_center(shapes)
        if center is not None:
            draw_name(name, center)

def draw_map_for_query(term='my job'):
    """Draw the sentiment map corresponding to the tweets that contain term.

    Some term suggestions:
    New York, Texas, sandwich, my life, justinbieber
    """
    tweets = load_tweets(make_tweet, term)
    tweets_by_state = group_tweets_by_state(tweets)
    state_sentiments = average_sentiments(tweets_by_state)
    draw_state_sentiments(state_sentiments)
    for tweet in tweets:
        s = analyze_tweet_sentiment(tweet)
        if has_sentiment(s):
            draw_dot(tweet_location(tweet), sentiment_value(s))
    wait()

def swap_tweet_representation(other=[make_tweet_fn, tweet_text_fn,
                                     tweet_time_fn, tweet_location_fn]):
    """Swap to another representation of tweets. Call again to swap back."""
    global make_tweet, tweet_text, tweet_time, tweet_location
    swap_to = tuple(other)
    other[:] = [make_tweet, tweet_text, tweet_time, tweet_location]
    make_tweet, tweet_text, tweet_time, tweet_location = swap_to


@main
def run(*args):
    """Read command-line arguments and calls corresponding functions."""
    import argparse
    parser = argparse.ArgumentParser(description="Run Trends")
    parser.add_argument('--print_sentiment', '-p', action='store_true')
    parser.add_argument('--draw_centered_map', '-d', action='store_true')
    parser.add_argument('--draw_map_for_query', '-m', action='store_true')
    parser.add_argument('--use_functional_tweets', '-f', action='store_true')
    parser.add_argument('text', metavar='T', type=str, nargs='*',
                        help='Text to process')
    args = parser.parse_args()
    if args.use_functional_tweets:
        swap_tweet_representation()
        print("Now using a functional representation of tweets!")
        args.use_functional_tweets = False
    for name, execute in args.__dict__.items():
        if name != 'text' and execute:
            globals()[name](' '.join(args.text))
